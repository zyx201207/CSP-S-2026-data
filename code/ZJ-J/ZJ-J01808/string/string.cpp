#include <bits/stdc++.h>
using namespace std;
long long n,s;

struct cchar{
	long long num;
	char ch;
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	//int a;
	//char c;
	for (int i=1;i<=n;i+=1){
		cin>>a[i].num>>a[i].ch;
		//s+=a[i].num;
		//cin>>a>>c;
		//for (int j=0;j<a;j+=1) str.push_back(c);
	}
	/*
	int l=0,r=str.size()-1;
	while (l<r){
		if (str[l]!=str[r]) s+=1;
		l+=1;
		r-=1;
	}
	cout<<s;
	*/
	
	int l=1,r=n;
	while(l<r){
		if (a[l].ch!=a[r].ch){
			s+=min(a[l].num,a[r].num);
		}
		if (a[l].num>a[r].num){
			a[l].num-=a[r].num;
			r-=1;
		}else if (a[l].num<a[r].num){
			a[r].num-=a[l].num;
			l+=1;
		}else{
			l+=1;
			r-=1;
		}
	}
	cout<<s;
	return 0;
}
