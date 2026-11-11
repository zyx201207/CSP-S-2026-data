#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,m[200005],x=0,y=0;
	char a[200005],b[1000005];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> m[i] >> a[i];
		for(int j=0;j<m[i];j++){
			b[x]=a[i];
			x++;
		}
	}
	for(int i=0;i<(x+1)/2;i++){
		if(b[i]!=b[x-i+1]){
			y++;
		}
	}
	cout << y;
	//fclose(stdin);
	//fclose(stdout); 
	return 0;
}
