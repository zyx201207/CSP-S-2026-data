#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,t,t1,l,sum,r;
string s[200005],b[200005];
int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>a[0]>>b[0];
	for(int i=1;i<n;i++){
		int d;
		string c;
		cin>>d>>c;
		m+=d;
		if(c==b[t]){
			a[t]+=d;
		}else{
			a[t+1]=d;
			b[t+1]=c;
			t++;
		}
	}m/=2;
	if(t==1){
		cout<<'0';
		return 0;
	}if(t==2){
		cout<<min(a[0],a[1]);
		return 0;
	}for(int i=0;i<t;i++){
		int j=t-1;
		l+=a[i];
		if(l<=m){
			if(b[i]==b[j]) sum+=abs(a[i]-a[j]);
			else sum+=min(a[i],a[j]);
		}j--;
	}cout<<sum;
	return 0;
}
