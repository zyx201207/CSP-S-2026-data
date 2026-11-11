 #include<bits/stdc++.h>
 using namespace std;
 int n,m,ans=0;
 int cnt[300005];
 int main()
 {
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n;i++)
 	{
 		int a;
 		scanf("%d",&a);
 		cnt[a]++;
 	}
 	for(int i=1;i<=m;i++)
 	{
 		ans+=cnt[i];
 		printf("%d ",ans);
 	}
 	return 0;
 }