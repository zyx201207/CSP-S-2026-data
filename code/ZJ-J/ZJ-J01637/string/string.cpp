#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s="";
	long long a[200005];
	char c[200005];
	cin>>n;
	long long len;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long cnt=0;
	int i=1,j=n;
	while(i<j){
		if(a[i]==a[j]){
			if(c[i]!=c[j])cnt+=a[i];
			i++;
			j--;
		}else if(a[i]<a[j]){
			if(c[i]!=c[j])cnt+=a[i];
			a[j]-=a[i];
			i++;
		}else{
			if(c[i]!=c[j])cnt+=a[j];
			a[i]-=a[j];
			j--;
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
