#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	for(;'9'<c||c<'0';c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x=f*x;
}
struct node{
	int cd,zf;
}a[2*100005];
stack<node> st;
int n;
long long zc=0,ans=0,b=0,k=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(n);
	char c;
	for(int i=1;i<=n;i++){
		read(a[i].cd);
		zc+=a[i].cd;
		cin>>c;
		a[i].zf=c-'a';
	}
	for(int i=1;i<=n;i++){
		if(b+a[i].cd>(zc/2)){
			st.push({a[i].cd-(a[i].cd+b-(zc/2)),a[i].zf});
			a[i].cd-=a[i].cd-(a[i].cd+b-(zc/2));
			b=i;
			break;
		}
		else if(b+a[i].cd==(zc/2)){
			st.push({a[i].cd,a[i].zf});
			b=i+1;
			break;
		}
		b+=a[i].cd;
		st.push(a[i]);
	}
//	cout<<zc;
//	cout<<a[b].cd<<" ";
//	cout<<st.size()<<" ";
//	while(!st.empty()){
//		cout<<st.top().cd<<" ";
//		st.pop();
//	}
//	cout<<b<<" ";
	if(zc%2==1)a[b].cd--;
	for(int i=b;i<=n;i++){
		int aa=st.top().cd;
		int bb=st.top().zf;
		st.pop();
		if(aa>=a[i].cd){
			if(a[i].zf!=bb){
				ans+=a[i].cd;
//				cout<<aa<<" "<<ans<<endl;
			}
			aa-=a[i].cd;
			if(aa>0){
				st.push({aa,bb});
			}
		}
		else{
			bool bl=false;
			int cc=aa;
			int kk=a[i].cd;
			while(a[i].cd){
				if(bl){
					aa=st.top().cd;
					bb=st.top().zf;
					st.pop();
				}
				if(aa<a[i].cd){
					if(a[i].zf!=bb){
						ans+=aa;
					}
					a[i].cd-=aa;
				}
				else{//a[i].cd<=cc
					if(a[i].zf!=bb){
						ans+=a[i].cd;	
					}
					aa-=a[i].cd;
					if(aa>0){
						st.push({aa,bb});
					}
					break;
				}
				if(!bl)bl=true;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/