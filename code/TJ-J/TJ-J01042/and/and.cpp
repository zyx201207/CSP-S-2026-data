#include<bits/stdc++.h>
using namespace std;
int dog[200002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>dog[i];
}
if(m==1){
	int max=0;
	for(int i=0;i<n;i++){
		if(dog[i]>max){
			max=dog[i];
		}
	}
	cout<<max;
	return 0;
}
int min=dog[0]&dog[1];
int f=n;
for(int i=0;i<f;i++){
	for(int j=0;j<n;j++){
		if(dog[i]&dog[j]>min){
			min=dog[i]&dog[j];
		}
	}
	f--;
}
cout<<min; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

