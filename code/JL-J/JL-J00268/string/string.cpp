#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct st{
	string str;
	long long l;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long s=0,n,ans=0;
	string k;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].l>>a[i].str;
		s+=a[i].l;
		k+=a[i].str;
	}
	/*
	if(s%2==0){
		string o=k;
		reverse(o.begin(),o.end());
		for(size_t i=0;i<k.size()/2;i++){
			if(k[i]!=o[i]){
				anss+=a[i].l;
			}
		}
		for(size_t i=k.size()/2;i<k.size();i++){
			if(k[i]!=o[i]){
				anns+=a[i].l;
			}
		}
		cout<<min(anns,anss)<<endl;
	}
	//else{
	//	
	//}*/
	int q=0,p=n-1;
	while(q<=p){
		if(a[q].str!=a[p].str){
			if(a[q].l<=a[p].l){
				ans+=a[q].l;
				a[p].l-=a[q].l;
				a[q].l=0;
			}
			if(a[p].l<=a[q].l){
				ans+=a[p].l;
				a[q].l-=a[p].l;
				a[p].l=0;
			}	
		}
		else{
			if(a[q].l<=a[p].l){
				//ans+=a[q].l;
				a[p].l-=a[q].l;
				a[q].l=0;
			}
			if(a[p].l<=a[q].l){
				//ans+=a[p].l;
				a[q].l-=a[p].l;
				a[p].l=0;
			}	
		}
		if(a[q].l==0){
			q++;
		}
		if(a[p].l==0){
			p--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
