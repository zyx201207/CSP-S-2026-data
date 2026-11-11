#include <bits/stdc++.h>
using namespace std;
int n;
char x[3];
int y[3];
int main (){
	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	cin>>n;
	int sum,a=1,sl=0;
	for (int i=0;i<n;i++){
		cin>>y[i];
		cin>>x[i];
		sl+=y[i];
	}
	char s[sl];
	for (int i=0;i<n;i++){
		for (int j=0;j<y[i];j++){
			s[a]=x[i];
			a++;
		}
	}
	
	if (sl%2==1){
		a=sl/2;
		int b=1;
		sum=sl/2;
		for (int i=a+2;i<=sl;i++){
			if (s[i]==s[i-2*b]){
				sum--;
				b++;
			}
		}
	}else{
		a=sl/2;
		int b=1;
		sum=sl/2;
		for (int i=a+1;i<=sl;i++){
			if (s[i]==s[i-2*b+1]){
				sum--;
				b++;
			}
		}
	}
	cout<<sum;
	
	
	
	
	
	
	fclose(stdin);
 	fclose(stdout);
	return 0;
}

