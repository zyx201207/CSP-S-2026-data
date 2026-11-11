#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
ll a[500010],cnt,b[500010],s[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++) b[j]=0;
		
		int cnt=0;
		
		//打出编号为j的牌 
		for(int j=i;j<=n;j++){
			
			bool f=0;
			int id=0;
			
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]){
					f=1;
					id=k;
					break;
				}
			}
			if(f==0) b[++cnt]=a[j];
			else{
				for(int k=id+1;k<=cnt;k++){
					b[k]=0;
				}
				cnt=id;
			}
		}
		for(int j=1;j<=cnt;j++){
			s[b[j]]++;
//			cout<<b[j]<<" ";
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
