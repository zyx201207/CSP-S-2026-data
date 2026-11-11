//SN-J00752 杨济铭 西安辅轮中学
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;ll cnt=0;
	cin>>n;
	int a[n];char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	long long half=(sum+1)/2;
	vector<char> s;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s.push_back(b[i]);
		}
	}
	ll r=sum;int c=0,e=n-1;ll ar=0,du=0;
	for(int i=0;i<half;i++){
		if(s[i]!=s[r]){
			cnt++;
		}
		r--;
	}
	/*while(r2<=half){
		r1=r2;
		if((half-max(ar,du))<a[c]){
			r2=half;
			cnt+=(r2-r1)*(b[e]!=b[c]);
			break;
		}else{
		ar+=a[c];du+=a[e];
		if(du<ar){
			r2+=a[e];
			ar-=a[c];
			cnt+=(r2-r1)*(b[e]!=b[c]);
			e--;
		}else if(ar==du){
			r2+=a[e];
			cnt+=(r2-r1)*(b[e]!=b[c]);
			c++;
			e--;
		}else{
			du-=a[e];
			r2+=a[c];
			cnt+=(r2-r1)*(b[e]!=b[c]);
			c++;
		}
	}
	}*/
	cout<<cnt;
	return 0;
}
