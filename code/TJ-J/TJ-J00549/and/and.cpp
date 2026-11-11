#include<bits/stdc++.h>
using namespace std;
long long a,b[200000+10],d[200000+10];
int n,m,c[20];
struct p{
	
}
bool cmp(p)
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a;
    	int cnt=0;
    	while(a){
    		c[++cnt]=a%2;
    		a/=2;
		}
		for(int j=cnt-1;j>=0;j++){
			b[i]+=c[j]*pow(10,j);
			if(c[j==1]) d[i]+=1;
		}
	}
	sort()
    return 0;
}
