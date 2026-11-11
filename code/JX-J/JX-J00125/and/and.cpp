#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt=1,mx,c[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        cnt=1;
        int b=a[i];
        for(int j=1;j<=n;j++) c[i]=0;
        for(int j=i+1;j<=n;j++){
            if(c[j]==0) b=b&a[j];
            c[j+1]=1;
            cnt++;
            if(cnt==m){
                mx=max(mx,b);
                cnt=1;
                b=a[i];
                j=i+1;
                break;
            }
        }
	}
	cout<<mx;
	return 0;
}
