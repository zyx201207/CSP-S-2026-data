#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,k; 
int a[N],cnt[N];
vector <int> v;
bool mark[N];
bool u=true;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i-1]>a[i]) u=false;
	}
	if(!u){
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(!mark[a[j]]){
					v.push_back(a[j]);
					mark[a[j]]=true;
				}
				else
					while(v.back()!=a[j])
					{
						mark[v.back()]=false;
						v.pop_back();
					}
			}
			while(!v.empty()){
				cnt[v.back()]++;
				v.pop_back();
			}
			for(int i=1;i<=m;i++)
				mark[i]=false;
		}
		for(int i=1;i<=m;i++)
			printf("%d ",cnt[i]);
	}
	else{
		for(int i=1;i<=n;i++)
			cnt[a[i]]++;
		for(int i=1;i<=m;i++)
			printf("%d ",cnt[i]%2);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
