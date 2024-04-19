/*
    ý tưởng:
    tạo mảng degree[] đại diện cho bậc của mỗi đỉnh, mảng edges[] là danh sách kề của mỗi đỉnh.
    vòng lặp n-2 lần thực hiện các bước sau:
    - tìm đỉnh có bậc nhỏ nhất và lưu lại chỉ số của nó.
    - tìm đỉnh kề với đỉnh vừa tìm và có chỉ số nhỏ nhất, lưu chỉ số này vào mảng prufer.
    - giảm bậc của đỉnh vừa tìm và bậc của nó đi 1.

    sau khi kết thúc vòng lặp chỉ còn lại 2 đỉnh có bậc bằng 1.
    in kết quả.

*/

#include <stdio.h>
#include <stdlib.h>

void prufer(int n, int edges[][2], int degree[])
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min_deg = n;
        int index_min;
        for (int j = 0; j < n; j++)
            if (degree[j] < min_deg && degree[j] != 0)
            {
                index_min = j;
                min_deg = degree[j];
            }
        // tim dinh co bac nho nhat, luu chi so cua no la index_min
        int min_vertex = n;
        for (int j = 0; j < n; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            if (u == index_min && degree[v] != 0)             // neu u la dinh co bac nho nhat vua tim, thi dinh v la dinh ke cua u
                                                              // kiem tra xem dinh v da bi loai khoi cay chua
                min_vertex = v < min_vertex ? v : min_vertex; // kiem tra xem chi so cua dinh v nho nhat hay chua

            if (v == index_min && degree[u] != 0)
                min_vertex = u < min_vertex ? u : min_vertex;
        }
        // tim dinh ke voi dinh index_min ma co chi so nho nhat
        printf("%d ", min_vertex);
        degree[min_vertex]--;
        degree[index_min] = 0;
    }
}

int main()
{
    int n, u, v;
    scanf("%d", &n);
    int edges[n + 1][2], degree[n + 1];
    for (int i = 0; i <= n; i++)
        degree[i] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    prufer(n, edges, degree);
    return 0;
}