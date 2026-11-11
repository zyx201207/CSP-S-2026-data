#include <bits/stdc++.h>
using namespace std;
int n,same=1,sum=0;
long long a[200005],c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    int mid=1+n/2;
    if(n%2==0){
	for(int i=1;i<=mid;i++){
            for(int j=n;j>mid;j++){
                if(c[i]!=c[j] && a[i]==a[j]){
		    same=0;
                    sum+=a[i];
	        }else if(c[i]==c[j] && a[i]!=a[j]){
                    same=0;
                    sum+=max(a[i],a[j])-min(a[i],a[j]);
                }else if(c[i]!=c[j] && a[i]!=a[j]){
                    same=0;
                    sum+=max(a[i],a[j])-min(a[i],a[j]);
                }
            }
        }
    }else{
        for(int i=1;i<mid;i++){
            for(int j=n;j>mid;j++){
                if(c[i]!=c[j] && a[i]==a[j]){
                    same=0;
                    sum+=a[i];
                }else if(c[i]==c[j] && a[i]!=a[j]){
                    same=0;
                    sum+=max(a[i],a[j])-min(a[i],a[j]);
                }else if(c[i]!=c[j] && a[i]!=a[j]){
                    same=0;
                    sum+=max(a[i],a[j])-min(a[i],a[j]);
                }
            }
        }
    }if(same==0) cout << 0;
    else cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

