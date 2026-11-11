#include<bits/stdc++.h>
using namespace std;
long long b[5001],f[5001],a[1000001],t,n,d,ans,num,c,l,cha;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=3){
			for(int i=1;i<=n;i++) cin>>a[1];
			cout<<0<<"\n";
			continue;
		}
		if(c==11 || c==12){
			cin>>a[1]>>a[2]>>a[3];
			for(int i=4;i<=n;i++){
				cin>>a[i];		
			}if(a[3]-a[1]>d){
				cout<<0<<"\n";
				continue;
			}cha=a[2]-a[1];
			cout<<max(1LL*0,n-2*(d/cha)+1)<<"\n";
			continue;
		}
		ans=num=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i];   
		}
		for(int i=1;i<=n;i++){
			b[i]=a[i]-a[1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(b[j]-b[i]<=d){
					continue;
				}ans=0;
				for(int k=i+1;k<j;k++){
					//cout<<"______"<<endl;
					if(b[k]-b[i]<=d && b[j]-b[k]<=d || b[j+1]-b[j]<=d && b[j+1]-b[k]>d){
						ans++;
					}
		
					if(ans>2) break;
				}if(ans==2)num++;
			}
		}cout<<num<<endl;
	}
	
	
	return 0;
}

