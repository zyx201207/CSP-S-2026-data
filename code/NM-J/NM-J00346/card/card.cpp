#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
const int INF=0x3f3f3f3f;
int n,m;
int a[N];
bool f=true;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=a[i+1]){
            f=false;
		}
	}
	if(f==true){
        for(int i=1;i<=m;i++){
            cout<<n<<" ";
        }
	}
	else{
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
	}
    return 0;
}
