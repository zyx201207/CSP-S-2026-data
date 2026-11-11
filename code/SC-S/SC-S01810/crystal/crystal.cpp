#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen ("crystal.in","r","stdin");
	freopen ("crystal.out","w","stdout");
    cin.tie();
 ll N=500001;
int n,l[N],p,ans=0,u,x;//n为水晶数，p为操作次数,l指代水晶值 
	cin>>n;
	cin>>p; 
for(int o=1;o<=n;o++){
	cin>>l[N];}
	for(int i=1;i<=n;i++){
	 if (p==0) {
	 	break;
	 }	
	for(int j=1;j<=i;j+=1)	
	{ 
	if(l[i]==l[i-1]&&l[i+1]==l[i]){
		
		ans++;
		break;
	}
	else if(l[i]-l[i-1]>=l[i+1]-l[i])
	{   while(u=u+1){
		 l[i]=l[i]+1;
		 p=p-1;
		 if(l[i]==l[i+1]) {
		ans++; 	
		break;
		 }
		 if(p==0){
		 	break;
		 }
	}
		 break;
	}
	else if(l[i+1]-l[i]>l[i]-l[i-1]){
	while(x+=1){
		l[i-1]=l[i-1]+1;
		 p=p-1;
	if(l[i]==l[i-1]){
	    ans++;
		break;
	}if(p==0){
		break;
	}
	}break;
}if(p==0){
	break;
}
}
}cout<<ans;

	return 0;
}