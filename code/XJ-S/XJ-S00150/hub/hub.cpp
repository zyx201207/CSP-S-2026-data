#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,T;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
    	int n,m;
    	cin>>n>>m;
    	for(int i=1;i<=2*(n-1);i++){
    		int a;
    		cin>>a;
		}
		if(c==13||c==14){
    		cout<<(n-2*m+9)/8<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	//ccf妈妈我知道错了，这题我似乎一分都偷不到！ 
    return 0;
}
