/*
    ? tý?ng:
    t?o m?ng degree[] ð?i di?n cho b?c c?a m?i ð?nh, m?ng edges[] là danh sách k? c?a m?i ð?nh.
    v?ng l?p n-2 l?n th?c hi?n các bý?c sau:
    - t?m ð?nh có b?c nh? nh?t và lýu l?i ch? s? c?a nó.
    - t?m ð?nh k? v?i ð?nh v?a t?m và có ch? s? nh? nh?t, lýu ch? s? này vào m?ng prufer.
    - gi?m b?c c?a ð?nh v?a t?m và b?c c?a nó ði 1.

    sau khi k?t thúc v?ng l?p ch? c?n l?i 2 ð?nh có b?c b?ng 1.
    in k?t qu?.

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
