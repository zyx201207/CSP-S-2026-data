#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dy(int x,int y){
	return x>y;
}
bool s(int i){
	int b=a[i];
	while(b){
		if(b%2==1){
			b/=2;
		}else{
			return false;
		}
	}
	return true;
}
int z=0,l=0,h=31,maxx=-1;//z是指针，l是拿了几个，h是拿的与的数； 
void dfs(){
	if(l>=m){
		if(h>maxx){
			maxx=h;
		}
		return;
	}
	if(z>n){
		return;
	}
	z++;
	l++;
	int g=h;
	h&=a[z];
	dfs();
	h=g;
	l--;
	dfs();
	z--;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n<=20){
		dfs(); 
		cout<<maxx<<endl;
	}else if(m==1||m==2){
    	sort(a+1,a+n+1,dy);
    	cout<<a[1]<<endl;
	}else if(m==n){
		int c=a[1];
		for(int i=2;i<=n;i++){
			c&=a[i];
		}
		cout<<c<<endl;
	}else if(m==n-1){
		sort(a+1,a+n+1,dy);
		int c=a[1];
		for(int i=2;i<n;i++){
			c&=a[i];
		}
		cout<<c<<endl;
	}else if(a[1]<=3&&a[2]<=3&&a[3]<=3){
		sort(a+1,a+n+1,dy);
		int d=0,e=0,f=0;
		while(a[d+1]==3){
			d++;
		}
		while(a[e+d+1]==2){
			e++;
		}
		while(a[f+e+d+1]==1){
			f++;
		}
		if(d>=m){
			cout<<"3"<<endl;
		}else if(d+e>=m){
			cout<<"2"<<endl;
		}else if(d+f>=m){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}else if(s(1)&&s(2)&&s(3)){
		sort(a+1,a+n+1,dy);
		cout<<a[m]<<endl;
	}else{
		sort(a+1,a+n+1,dy);
		int c=a[1];
		for(int i=2;i<=m;i++){
			c&=a[i];
		}
		cout<<c<<endl;
	}
	return 0;
}
