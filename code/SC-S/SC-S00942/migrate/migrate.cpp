#include<bits/stdc++.h>

using namespace std;
int n;long long  d;
long long a[1000000];int tmp=0;
void dfs(int p,int r,int now,int k){
	if(now==k){
		if(p==r){
			tmp++;
		}
		return;
	}else{
		for(int i=p+1;i<=r;i++){
			if(a[i]-a[p]<=d){
				dfs(i,r,now+1,k);
			}
		}
	}
}
int check(int l,int r){
	int p=l;int num=0;
	while(p!=r){
		bool flag=0;
		for(int i=r;i>=p+1;i--){
			if(a[i]-a[p]<=d){
				num++;
				p=i;flag=1;
				break;
			}
		}
		if(flag==0){
			return 0;
		}
	}tmp=0;
	dfs(l,r,0,num);
	if(tmp==2){
		return 1;
	}else{
		return 0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;cin>>c;
	int T;cin>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n;cin>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n<=3){
				cout<<0<<endl;continue;
			}
			long long cha=a[2]-a[1];
			long long step=d/cha;
			if(step<=1){
				cout<<0<<endl;
			}else{
				long long ans=n-(2*step)+1;
				if(ans<0){
					cout<<0<<endl;
				}else{
					cout<<ans<<endl;
				}
			} 
		}
	}else{
		while(T--){
			cin>>n;cin>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n<=3){
				cout<<0<<endl;
				continue; 
			}
			int ans=0;
			for(int l=1;l<=n;l++){
				for(int r=l+3;r<=n;r++){
					ans+=check(l,r);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}