#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,ma=0;
int a[N],b[N],s[5010][5010];
int boo(int x,int y){
	int k=y-x;
    s[x][y]=s[x][y-1]+k*b[y];
    return s[x][y];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		//cout<<a[i]<<" "<<b[i]<<endl;
	}
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum;
            sum=boo(i,j);
            if(sum>m) break;
            else ma=max(ma,j-i+1);
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) cout<<s[i][j]<<" ";
    }*/
    cout<<ma;
    return 0;
    //Oct31==Dec25?
}
