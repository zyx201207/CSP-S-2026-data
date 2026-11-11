#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int n, d;
void solve(int x){
	int cnt=0;
	int minn=0;
	if((x*(n-1))%d==0){
		minn=(x*(n-1))/d;
		cnt++;
	}
	else{
		minn=(x*(n-1))/d;
		cnt++;
	}
	if(minn!=2){
		cout<<0;
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int q=x*(j-i);
			bool f=1;
			int t;
			int p;
			for(int i=d-1;i>=1;i--){
				p=0;
				if(q%i==0){
					p=q/i;
					if(p!=2){
						f=0;
					}
				}
				else{
					p=q/i+1;
					if(p!=t){
						f=0;
					}
				}
			}
			if(f){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cha=a[2]-a[1];
		solve(cha);
	}
	return 0;
}
