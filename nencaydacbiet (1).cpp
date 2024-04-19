/*
    ? t�?ng:
    t?o m?ng degree[] �?i di?n cho b?c c?a m?i �?nh, m?ng edges[] l� danh s�ch k? c?a m?i �?nh.
    v?ng l?p n-2 l?n th?c hi?n c�c b�?c sau:
    - t?m �?nh c� b?c nh? nh?t v� l�u l?i ch? s? c?a n�.
    - t?m �?nh k? v?i �?nh v?a t?m v� c� ch? s? nh? nh?t, l�u ch? s? n�y v�o m?ng prufer.
    - gi?m b?c c?a �?nh v?a t?m v� b?c c?a n� �i 1.

    sau khi k?t th�c v?ng l?p ch? c?n l?i 2 �?nh c� b?c b?ng 1.
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
