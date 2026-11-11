# include <bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char ch;
};
queue<node> Q,V,X;
node A[100100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long x,len=0,m,ans=0,qq=0,sum=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		Q.push((node){x,c});
		X.push((node){x,c});
		sum+=x;
	}
	while(!Q.empty()){
		node u=Q.front();
		Q.pop();
		A[++qq]=u;
	}
	for(int i=qq;i>=1;i--) V.push(A[i]);
	m=sum/2;
	while(len<m){
		node u=X.front(),v=V.front();
		X.pop();V.pop();
		long long minn=min(u.a,v.a);
		if(len+minn>m) minn=m-len;
		if(u.a==v.a){
			if(u.ch==v.ch) len+=minn;
			else{
				len+=minn;
				ans+=minn;
			}
		}
		else if(u.a>v.a){
			if(u.ch==v.ch){
				len+=minn;
				qq=0;
				while(!X.empty()){
					node l=X.front();
					A[++qq]=l;
					X.pop(); 
				}
				X.push((node){u.a-v.a,u.ch});
				for(int i=1;i<=qq;i++) X.push(A[i]);
			}
			else{
				len+=minn;
				qq=0;
				ans+=minn;
				while(!X.empty()){
					node l=X.front();
					A[++qq]=l;
					X.pop(); 
				}
				X.push((node){u.a-v.a,u.ch});
				for(int i=1;i<=qq;i++) X.push(A[i]);
			}
		}
		else if(u.a<v.a){
			if(u.ch==v.ch){
				len+=minn;
				qq=0;
				while(!V.empty()){
					node l=V.front();
					A[++qq]=l;
					V.pop(); 
				}
				V.push((node){v.a-u.a,v.ch});
				for(int i=1;i<=qq;i++) X.push(A[i]);
			}
			else{
				len+=minn;
				qq=0;
				ans+=minn;
				while(!V.empty()){
					node l=V.front();
					A[++qq]=l;
					V.pop(); 
				}
				V.push((node){v.a-u.a,v.ch});
				for(int i=1;i<=qq;i++){
					V.push(A[i]);
				} 
			}
		}
	}
	cout<<ans;
	return 0;
} 
