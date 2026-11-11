#include<bits/stdc++.h>
using namespace std;
long long n , m , a[200005] , sum;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.iout","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	if(n==m){
		sum=a[1];
		for(int i = 2;i<=n;i++)sum&=a[i];
		cout<<sum;
		return 0;
	}else if(m==1){
		long long mx = 0;
		for(int i = 1;i<=n;i++)mx = max(mx,a[i]);
		cout<<mx;
		return 0;	
	}else if(m==2){
		long long mxx = 0,mx = 0;
		for(int i = 1;i<=n;i++){
			mxx = 0;
			for(int j = 1;j<i;j++){
				mxx = max(a[i]&a[j],mxx);
			}
			mx = max(mx,mxx);
		}
		cout<<mx;
		return 0;
	}
	long long d[m][n];
	sort(a+1,a+n+1,cmp);
	for(int i = 0;i<=m;i++)d[i][0]=1;
	for(int i = 0;i<=n;i++)d[0][i]=1;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++)d[i][j]=max(d[i-1][j-1]&a[j],max(d[i-1][j],d[i][j-1]&a[j]));
	}
	cout<<d[m][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
