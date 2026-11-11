#include<iostream
using namespace std;
char h[100005];
char l[100005];
int count = 0;
bool k(int n){
	int p = 0;
	for(int i = n;i>=0;i--){
		l[i] = h[count-1-i];
	}
	for(int i = 0;i<n;i++){
		if(h[i] == l[i]) p++;
	}
	if(p == n) return 1;
	return 0;
}
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int n1;
		char m;
		cin>>n1>>m;
		for(int j = count;j<count+n1;j++){
			h[j] = m;
		}
		count+=n1;
	}
	if(k(count) == 1) cout<<0;
	else{
		int h1 = 0;
		if(count%2 == 0){
			for(int i = 0;i<int(count/2);i++){
				if(h[count-i-1] != h[i]) h1+=1;
			}
		}
		else{
			for(int i = 0;i<int(count/2)+1;i++){
				if(h[count-i-1] != h[i]) h1+=1;
			}
		}
		cout<<h1;
	}
	return 0;
}
