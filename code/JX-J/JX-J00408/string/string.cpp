#include<bits/stdc++.h>
using namespace std;
int a,n;
long long num;
char c;
string s;
struct Node{
	int b;
	char c;
}arr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
		cin>>arr[i].b>>arr[i].c;
		n+=arr[i].b;
		//cout<<n<<endl;
    }
    int l=1,r=a;
    while(l<=r){
		//cout<<l<<' '<<r<<' '<<arr[l].b<<' '<<arr[r].b<<' '<<num<<endl;
		if(arr[l].c!=arr[r].c){
			if(arr[l].b<arr[r].b){
				num+=arr[l].b;
				arr[r].b-=arr[l].b;
				l++;
			}
			else if(arr[l].b>arr[r].b){
				num+=arr[r].b;
				arr[l].b-=arr[r].b;
				r--;
			}
			else{
				num+=arr[r].b;
				l++,r--;
			}
		}
		else{
			if(arr[l].b<arr[r].b){
				arr[r].b-=arr[l].b;
				l++;
			}
			else if(arr[l].b>arr[r].b){
				arr[l].b-=arr[r].b;
				r--;
			}
			else{
				l++,r--;
			}
		}
	}
	cout<<num;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int a,b,n;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>a;
    while(a--){
        cin>>b>>c;
        while(b--) s+=c;
    }
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]) n++;
        l++;
        r--;
    }
    cout<<n;
	return 0;
}
*/
