# include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],b[500100],sum,cnt,ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-2;i++){
		sum=0;
		cnt=0;
		for(int j=i;j<=n-1;j++){
			if(b[j]==0) cnt++;
			else{
				sum+=b[j]*(j-i+1);
				cnt++;
			}
			if(sum<=m&&cnt>ma){
				ma=cnt;
			}
		}
	}
	cout<<ma+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
