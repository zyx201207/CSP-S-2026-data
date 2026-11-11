#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
bool check(int x,int y){
    long long s=0;
    for(int k=x+1;k<=y-1;k++){
        if(abs(a[x]-a[k])<=d&&abs(a[y]-a[k])<=d){
            s++;
        }
    }
    if(s==2){return 1;}
    else {return 0;}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
        	cin>>a[i];
		}
        long long sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(check(i,j)){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
	}
	return 0;
}
