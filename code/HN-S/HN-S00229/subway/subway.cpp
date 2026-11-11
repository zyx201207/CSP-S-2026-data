#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[500005],k[505],a[505][500005],t[505][500005];
bool mapp[500005][500005];
int tt,minn,md;//Ãªµã 
//void by(int )
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i ++)
		scanf("%d ",&w[i]);
	for(int i = 1;i <= m;i ++)
	{
		scanf("%d ",&k[i]);
		for(int j = 1;j <= k[i];j ++)
		{
			scanf("%d %d ",&a[i][j],&t[i][j]);
			if(j == k[i])
				for(int p = 1;p <= k[i];p ++)
					for(int q = p + 1;q <= k[i];q ++)
						mapp[p][q] = 1;
		}	
	}
	for(int i = 1;i <= q;i ++)
	{
		scanf("%d %d ",&x,&y);
		if(c >= 7 && c <= 11){
			md = x;
			while(md == x)
			{
				tt += t[x]
			}
		}
		
	}
	
	
	



	return 0;
}
