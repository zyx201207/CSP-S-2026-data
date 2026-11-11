#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+10;
int P[N];
int C[N];
long long sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int t=n;
    while(n--){
    	int num;
    	char c;
    	cin>>num>>c;
    	P[n+1]=num;
    	C[n+1]=int(c);
	}
	
	/*for(int i=1;i<=t;i++){
		cout<<i<<" "<<P[i]<<" "<<C[i]<<endl;
	}*/
	for(int i=1;i<=t;i++){
		int d=t+1-i;
		if(C[i]!=C[d]){
			//cout<<min(P[i],P[d])<<endl;
			sum+=min(P[i],P[d]);
			sum+=abs(P[d]-P[i]);
		}
	}
	cout<<sum/2;
    return 0;
}


