#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,b=0,n,ans=0;
    string x;
    string y;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        scanf("%d",&x);
        for(int j=1;j<=a;j++){
            y[b]=x[0];
            b++;
        }
    }
    b--;
    long long num=b;
    for(int i=0;i<num/2;i++){
        /*for(int j=num;j>=num/2;j--){
            if(y[i]!=y[j]){
                ans++;
            }
        }*/
		if(y[i]!=y[b]){
			ans++;
		}
		b--;
	}
	cout<<ans;
    return 0;
}
