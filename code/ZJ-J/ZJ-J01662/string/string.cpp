#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	char v;
}a[200005];
int main(){
	 freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);
	 int n;
	 cin>>n;
	 int cnt=0;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i].id>>a[i].v;
	 	cnt++;
	 }
	 cnt/=2;
	 int i=1;
	 int j=n;
	 bool flagx=true;
	 bool flagy=true;
	 long long ans=0;
	 int x=0;
	 int y=0;
	 while(i<j){
	 	if(flagx==true){
	 		x+=a[i].id;
	 		flagx=false;
		 }
	 	if(flagy==true){
	 		y+=a[j].id;
	 		flagy=false;
		 }
	 	if(a[i].v!=a[j].v){
	 		if(x>=y){
	 			ans+=y;
	 			x-=y;
	 			j--;
	 			y=0;
	 			flagy=true;
			 }
			 else{
			 	ans+=x;
	 			y-=x;
	 			i++;
	 			x=0;
	 			flagx=true;
			 }
		 }
		 else{
		 	if(x>=y){
	 			x-=y;
	 			j--;
	 			y=0;
	 			flagy=true;
			 }
			 else{
	 			y-=x;
	 			x=0;
	 			i++;
	 			flagx=true;
			 }
		 }
	 	 //cout<<x<<" "<<y<<endl;
	 	 //cout<<i<<" "<<j<<" "<<ans<<endl;
	 	 //cout<<endl;
	 }
	 cout<<ans;
	return 0;
}
