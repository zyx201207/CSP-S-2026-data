#include<bits/stdc++.h>
using namespace std;
int a[500010],cnt[300010],c[500010];
map<int,int>b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				for(int w=c[a[j]];w<=j;w++){
					b[a[w]]=0;
					c[a[w]]=0;
				}
			}
			b[a[j]]=1;
			c[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			//cout<<j<<" "<<b[j]<<"##"<<" ";
			if(b[j]==1){
				cnt[j]++;
				//cout<<j<<" "<<cnt[j]<<"**"<<" ";
			}
		}
		//cout<<endl;
		b.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

