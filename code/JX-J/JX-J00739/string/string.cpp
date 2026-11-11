#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,tl=0;
	cin>>n;
	vector<long long> a(n);
	vector<char> c(n);
	for(int i=0;i<n;i++){
			cin>>a[i]>>c[i];
			tl+=a[i];
	}
	long long an=0,l=0,r=n-1;
	long long al=a[l],ar=a[r];
	while(l<r){
		long long ml=min(al,ar);
		if(c[l]!=c[r]) an+=ml;
		al-=ml;
		ar-=ml;
		if(al==0){
			l++;
			if(l<n)al=a[l];
		}
		if(ar==0){
			r--;
			if(r>=0)ar=a[r];
		}
	}
	cout<<an;
	return 0;
}
