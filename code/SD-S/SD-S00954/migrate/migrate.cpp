#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,l[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> a >> a;
	while(a--){
		cin >> b >> c;
		for(long long i=1;i<=b;i++){
			cin >> l[i];
		}
		if(b<=300){
			long long t=0;
			for(long long i=1;i<=b;i++){
				for(long long j=i+3;j<=b;j++){
					if(l[j]-l[i]<=c){
						continue;
					}
					long long ans=0;
					for(long long k=i+1;k<j;k++){
						if(l[k]-l[i]<=c&&l[j]-l[k]<=c){
							ans++;
						}
					}
					if(ans==2){
						t++;
					}
				} 
			}
			cout << t << "\n";
		}else{
			if((l[2]-l[1])*2<=c&&c<(l[2]-l[1])*3){
				cout << b-3 << "\n";
			}else if(c==(l[2]-l[1])*3){
				cout << b-5 << "\n";
			}else{
				cout << 0 << "\n";
			}
		}
	}
	return 0;
} 
