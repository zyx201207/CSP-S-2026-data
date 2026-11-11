#include<iostream>
using namespace std;
int n,x,y,z,c,cnt;
char a[200005],b[200005];
int main(){
	freopen("string.in","r",std.in);
	freopen("string.out","w",std.out);
	cin>>n;
	for(int i=0;i<n;i++){
		z=x;
		cin>>x>>a[i];
		for(y=z;y<+x;y++){
			b[y]=a[i];
			c++;
		}
	}
	for(int j=0;j<=c/2;j++){
		if(b[j]!=b[c-1-j]){
			break;
		}
		else{
			cnt++;
		}
	}
	if(cnt>=c/2){
		cout<<0;
	}
	else{
		cout<<2;
	}
	return 0;
}
