#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	int a;
	char c;
}s[200005];
long long slong;
long long l,r;
long long step;
int main(){
 	freopen("string.in","r",stdin);
  	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>s[i].a>>s[i].c;
    	slong+=s[i].a;
	}
	l=1;
	r=slong;
	long long to1=1;
	long long to2=n;
	if(slong%2==1){
		while(l<r-1){
			if(s[to1].c==s[to2].c){
				r-=min(s[to1].a,s[to2].a);
				l+=min(s[to1].a,s[to2].a);
				if(s[to1].a>s[to2].a){
					s[to1].a-=s[to2].a;
					to2--;
				}else if(s[to2].a>s[to1].a){
					s[to2].a-=s[to1].a;
					to1++;
				}else{
					to2--;
					to1++;
				}
			}else{
				step+=min(s[to1].a,s[to2].a);
				r-=min(s[to1].a,s[to2].a);
				l+=min(s[to1].a,s[to2].a);
				if(s[to1].a>s[to2].a){
					s[to1].a-=s[to2].a;
					to2--;
				}else if(s[to2].a>s[to1].a){
					s[to2].a-=s[to1].a;
					to1++;
				}else{
					to2--;
					to1++;
				}
			}
		}
	}else{
		while(l<r){
			if(s[to1].c==s[to2].c){
				r-=min(s[to1].a,s[to2].a);
				l+=min(s[to1].a,s[to2].a);
				if(s[to1].a>s[to2].a){
					s[to1].a-=s[to2].a;
					to2--;
				}else if(s[to2].a>s[to1].a){
					s[to2].a-=s[to1].a;
					to1++;
				}else{
					to2--;
					to1++;
				}
			}else{
				step+=min(s[to1].a,s[to2].a);
				r-=min(s[to1].a,s[to2].a);
				l+=min(s[to1].a,s[to2].a);
				if(s[to1].a>s[to2].a){
					s[to1].a-=s[to2].a;
					to2--;
				}else if(s[to2].a>s[to1].a){
					s[to2].a-=s[to1].a;
					to1++;
				}else{
					to2--;
					to1++;
				}
			}
		}
	}
	cout<<step;
	return 0;
} 
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

