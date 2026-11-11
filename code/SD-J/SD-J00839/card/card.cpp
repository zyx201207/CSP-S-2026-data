#include<bits/stdc++.h>
using namespace std;
int n,m;
struct q{
	int num;
}a[100010];
int sum;
int ans[100010];
int w[100010];
bool b[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].num;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(b[a[j].num]==0){
				ans[sum]=a[j].num;
				sum++;
				b[a[j].num]=1;
			}else{
				for(int i1=0;i1<sum;i1++){
					if(ans[i1]==a[j].num){
						//cout<<i<<' '<<j<<' '<<i1<<" "<<ans[i1]<<" "<<a[j].num<<'\n';
						for(int g=i1;g<sum;g++){
							if(a[g].num!=a[j].num){
								b[a[g].num]=0;
								//cout<<a[g].num<<" ";
							}
						}
						sum=i1+1;
						//cout<<'\n';
						break;
					}
				}
			}	
		}for(int i1=0;i1<sum;i1++){
			//cout<<ans[i1]<<" ";
			w[ans[i1]]++;
		}
		//cout<<'\n';
		for(int j=0;j<sum;j++){
			//cout<<ans[j]<<" ";
			ans[j]=0;
		}for(int j=1;j<=m;j++){
			b[j]=0;
		}
		sum=0;
	}
	for(int i=1;i<=m;i++){
		cout<<w[i]<<" ";
	}
	return 0;
}
