#include<bits/stdc++.h>
using namespace std;
long long n,m,mx,ss;
struct node{
	long long a,b;
}f[200005];
bool cmp(node x,node y){
	return x.b>y.b||x.b==y.b&&x.a>y.a;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
    	cin>>f[i].a;
	}
	if(m==n){
	
		for(int i=1;i<n;i++){
			ss=f[i].a&f[i+1].a;
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ss=max(ss,f[i].a);
		}
	}else{
		for(int i=1;i<=n;i++){
			f[i].b=f[i].a;
			while(f[i].b){
				f[i].b=f[i].b&(f[i].b-1);
				mx++;
			}
			f[i].b=mx;
		} 
		sort(f+1,f+1+n,cmp);
		
		for(int i=1;i<=n;i++){
			mx=f[i].a&f[i+1].a;
			for(int j=i;j<m;j++){
				mx=mx&f[j+1].a;
			}
			ss=max(mx,ss);
		}
	}
    cout<<ss;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

