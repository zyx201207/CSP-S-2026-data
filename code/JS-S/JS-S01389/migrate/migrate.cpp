#include<bits/stdc++.h>
using namespace std;
long long c,n[2333333];
int sw(int s,int f){
    int t=1,t2=s;
    for(int i=s;i<f;i++){
    	if(n[i+1]-n[t2]>c){
    	    if(t2==i) return -1;
    	    else{t++;t2=i+1;}
    	}
    }
    return t;
}
int dfs(int s,int f,int d){
    int t=0;
    if((s<f && d==0) or (s==f && d!=0)) return 0;
    else if(s==f && d==0) return 1;
    for(int i=s+1;i<=f;i++){
    	if(n[i]-n[s]<=c) t+=dfs(i,f,d-1);
    	else break;
    }
    //printf("##In dfs(%d,%d,%d) returned %d\n",s,f,d,t);
    return t;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b,t=0;
    cin>>a;
    cin>>a;
    for(int i=0;i<a;i++){
    	cin>>b>>c;
    	t=0;
    	for(int j=0;j<b;j++) cin>>n[j];
    	for(int j=0;j<b;j++){
    	    for(int k=j+2;k<b;k++){
    	    	int t1=sw(j,k);
    	    	//printf("@@sw(%d,%d)=%d\n",j,k,t1);
    	    	if(t1==-1 or t1==1) continue;
    	    	else if(dfs(j,k,t1)==2) t++;
    	    }
    	}
    	cout<<t<<endl;
    }
    return 0;
}
