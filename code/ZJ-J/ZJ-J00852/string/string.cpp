#include<bits/stdc++.h>
using namespace std;
struct ee{
	long long a;
	char c;
};
int n;
deque<ee> qu;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		qu.push_back({a,c});
	}
	int l=0,r=qu.size()-1;
	while(r>0){
		if(qu[l].c==qu[r].c){
			long long k=min(qu[l].a,qu[r].a);
			qu[l].a-=k;
			qu[r].a-=k;
			if(qu[l].a==0){
				qu.pop_front();
				r--;
			}
			if(qu[r].a==0){
				qu.pop_back();
				r--;
			}
			
		}
		else {
			long long k=min(qu[l].a,qu[r].a);
			ans+=k;
			qu[l].a-=k;
			qu[r].a-=k;
			if(qu[l].a==0){
				qu.pop_front();
				r--;
			}
			if(qu[r].a==0){
				qu.pop_back();
				r--;
			}
//			if(qu[l].a>qu[r].a){
//				ans+=qu[r].a;
//				qu[l].a-=qu[r].a;
//				qu.pop_back();
//				r--;
//			}
//			if(qu[l].a==qu[r].a){
//				ans+=qu[r].a;
//				qu.pop_front();
//				qu.pop_back();
//				r-=2;
//			}
//			if(qu[l].a<qu[r].a){
//				ans+=qu[l].a;
//				qu[r].a-=qu[l].a;
//				qu.pop_front();
//				r--;
//			}
		}
	}
	cout<<ans;
}
