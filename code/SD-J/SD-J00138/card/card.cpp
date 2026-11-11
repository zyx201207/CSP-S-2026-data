#include<bits/stdc++.h>
using namespace std;
long long n,m,p[200005],a[100005];
bool v[200005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>p[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(v[p[j]]==0){
				v[p[j]]=1;
				
			}else{
				int c=j-1;
				while(1){
					if(p[c]==p[j]){
						break;
					}
					v[p[c]]=0;
					c--;
				}
			}
		}
		
		for(long long q=1;q<=m;q++){
			if(v[q]==1){
				a[q]++;
				v[q]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
