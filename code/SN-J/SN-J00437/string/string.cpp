#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct s{
	long long a;
	char c;
}q[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
	}
	int r=1,l=n;
	while(r!=l){
		while(q[r].a>0){
			//cout<<"1 "<<r<<" "<<q[r].a<<" "<<l<<" "<<q[l].a<<'\n';
		    if(q[r].c==q[l].c){
			    if(q[r].a>q[l].a){
			    	q[r].a-=q[l].a;
			    	q[l].a=0;
			    	l--;
				}else{
					q[l].a-=q[r].a;
					q[r].a=0;
				}
	    	}
	    
	    	else if(q[r].c!=q[l].c){
			    if(q[r].a>q[l].a){
			    	q[r].a-=q[l].a;
			    	ans+=q[l].a;
			    	q[l].a=0;
			    	l--;
				}else{
					q[l].a-=q[r].a;
					ans+=q[r].a;
					q[r].a=0;
				}
	    	}	
			//cout<<"2 "<<r<<" "<<q[r].a<<" "<<l<<" "<<q[l].a<<'\n';
    	}
    	if(l==r)break;
    	r++;
	}
	cout<<ans;
	return 0;
}
/*
5
6 a
6 b
12 c
6 b
6 a
*/
