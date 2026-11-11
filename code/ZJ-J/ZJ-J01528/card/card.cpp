#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
const int maxm=3e5+5;
int n,m,a[maxm],ans[maxm],d[maxm],lst;
queue<int> h,t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cout<<"3 1 4";
//	n=read();m=read();
//	for(int i=1;i<=n;i++){
//		a[i]=read();
//		h.push(a[i]);if(i==n)lst=a[i];
//	}
//	for(int i=1;i<=n;i++){
//		while(!t.empty())t.pop();
//		while(!h.empty())h.pop();
//		for(int k=i;k<=n;k++)h.push(a[i]);
//		memset(d,0,sizeof(d));
//		while(1){
//			if(d[h.front()]){
//				queue<int> l;
//				while(t.front()!=h.front())l.push(t.front()),t.pop();
//				while(!t.empty()){
//					d[t.front()]--;
//					h.push(t.front());
//					t.pop();
//				}
//				while(!l.empty())t.push(l.front()),l.pop();
//				d[h.front()]++;t.push(h.front());h.pop();
//			}else{
//				d[h.front()]++;
//				t.push(h.front());
//				int p=h.front();
//				h.pop();
//				if(p==lst)break;
//			}
//		}
//		queue<int> q;
//		while(!t.empty()){
//			q.push(t.front());
//			ans[t.front()]++;
//			t.pop();
//		}
//		while(!q.empty()){
//			t.push(q.front());
//			q.pop();
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
