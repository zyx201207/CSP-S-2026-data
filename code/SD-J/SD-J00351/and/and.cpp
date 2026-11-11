#include<iostream>
#include<set>
using namespace std;
int n,m,f,c,p,a[200001];
multiset<int> s;
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[0];
		s.insert(a[0]);
	}
	p=1<<30;
	for(int i=0;i<30;i++){
		p>>=1;
		c=0;
		n=0;
		for(auto t:s){
			if(t&p){
				c++;
			}else{
				a[n++]=t;
			}
		}
		if(c>=m){
			f|=p;
			for(int i=0;i<n;i++){
				s.erase(a[i]);
			}
		}
	}
	cout<<f;
	return 0;
} 
