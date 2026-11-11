#include<bits/stdc++.h>
using namespace std;
int T;
long long a[100010];
long long ans=0,sum=0,k=1,j=1;
char b[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> T;
	if(T==1){
		cout << 0;
		return 0;
	}
	for(int i=0;i<T;i++){
		cin >> a[i];
		sum += a[i];
		cin >> b[i];
		for(int j=k;j<k+a[i];j++){
			b[j]=b[i];
		}
		k+=a[i];
	}

	if(sum%2==0){j=sum/2;}
	else {j=sum/2-1;}
	for(int i=sum/2+1;i<sum;++i){	
		if(b[j]!=b[i]){
			ans++;
		}
		j--;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}