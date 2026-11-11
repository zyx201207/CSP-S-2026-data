#include<bits/stdc++.h>
using namespace std;
int c,t,n,num,ans;
long long d,x[2000010],minn;
struct node{
	int a,b,c;
};
int src(int na,int c_){
	for(int i=c_;i<=n;i++){
		if(x[i]==na) return i;
		if(x[i]<na) return 0;
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			int i_=x[i];
			for(int j=i+1;j<=n;j++){
				int j_=x[j];
				minn=2100000000;
				num=0;
				queue<node> que;
				node nod;
				nod.a=i_;
				nod.b=0;
				nod.c=i;
				que.push(nod);
				while(que.size()){
					node k=que.front();
					for(int l=1;l<=d;l++){
						if(src(l+k.a,l+k.c)==0) continue;
						//cout<<k.a<<" "<<k.b<<" "<<j_<<" "<<src(l+k.a,l+k.c)<<"  ";
						if(k.a+l==j_){
							if(k.b<minn){
								num=1;
								minn=k.b;
							}
							else if(k.b==minn){
								num++;
							}
						}
						node neww;
						neww.a=k.a+l;
						neww.b=k.b+1;
						neww.c=src(l+k.a,l+k.c);
						que.push(neww);
					}
					que.pop();
				}
				if(num==2) ans++;
				//cout<<num<<endl;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

