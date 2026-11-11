#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans,sum;
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	int i=1,j=n;
	long long last1=a[1],last2=a[n];
	while(sum<m/2){
		sum+=min(last1,last2);
		if(c[i]!=c[j]){
			ans+=min(last1,last2);
		}
		if(last1<last2){
			last2-=last1;
			i++;
			last1=a[i];	
		}
		else if(last1>last2){
			last1-=last2;
			j--;
			last2=a[j];
		}
		else{
			i++;
			last1=a[i];
			j--;
			last2=a[j];
		}
	}
	cout<<ans;
	return 0;
}
