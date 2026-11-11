#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],cnt;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1,j=n,ci=1,ji=1;j>i;ci++,ji++){
		if(ci>a[i]){
			i++;
			ci=1;
		}
		if(ji>a[j]){
			j--;
			ji=1;
		}
		if(b[i]!=b[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}