int n,m,a[500001],sum[300001],b[500001];
scanf("%d%d",&n,&m);
for (int i = 1;i <= n;i++)
    scanf("%d",&a[i]);
for (int i = 1;i <= n;i++){
    for (int j = i-1;j <= n;j++)
        b[j]=0;
    int zw = 0;
    for (int j = i;j <= n;j++){
        for (int k = 1;k <= zw;k++)
            if (b[k] == a[j])
                zw = k-1;
        zw++;
        b[zw] = a[j];
    }
    for (int j = 1,j <= zw;j++)
        sum[b[j]]++;
}
    for (int i = 1;i <= m;i++){
    printf("%d ",sum[i]);
}
return 0;
