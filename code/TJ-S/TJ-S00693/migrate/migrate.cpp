#include<bits/stdc++.h>
using namespace std;
int a[2000005],di[2000005],s[2000005];
bool v[2000005];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			if(i==1){
				di[1]=0;
				continue;
			}
			di[i]=a[i]-a[i-1];
			if(di[i]>d){
				v[i]=1;
			}
		}
		s[1]=di[1];
		for(int i=2;i<=n;i++){
			s[i]=s[i-1]+di[i];
		}
		int ans=0;
		for(int i=1;i<d;i++){
			for(int a=1;a<=n;a++){
				for(int b=a+1;b<=n;b++){
					if(v[b]){
						a=b;
						b++;
					}
					cout << s[b]-s[a]+di[a] << endl;
					if(s[b]-s[a]+di[a]<i+d){
						b++;
					}else if(s[b]-s[a]+di[a]>i+d){
						a++;
					}else{
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
