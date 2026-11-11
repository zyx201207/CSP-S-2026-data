#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ant=0;
	cin >>n;
	int a[n+1];
	string c[n+1],s,s1;
	for (int i=0;i<=n-1;i++){
		cin >>a[i]>>c[i];
		for (int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for (int i=n-1;i>=0;i--){
		for (int j=1;j<=a[i];j++){
			s1+=c[i];
		}
	}
	if (s==s1){
		cout <<0;
	}
	else{
		for (int i=0;i<=n-1;i++){
			for (int j=1;j<=a[i];j++){
				s[-(i+1)]=s[i];
				ant+=1;
				}
			}
		cout <<ant;
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
