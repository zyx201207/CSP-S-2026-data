#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	int flag=0; 
    int flag1=0;
    int flag2=0;
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    // first
    if(c1==c2){
    	flag=1;
    	cout << 1;
	}
    else cout << 0;
    // second
    if(flag==1 && s1[0]==s2[0] && s1[1]==s2[1]){
        flag1=1;
        cout << 1;
    }else cout << 0;
    // third
    if(flag1==1 && (s1[2]<='C'&&s2[2]<='C' || s1[1]>='D'&&s2[2]>='D')){
        flag2=1;
        cout << 1;
    }else cout << 0;
    // forth
    if(flag2==1 && abs(s1[2]-s2[2])<=1){
        cout << 1;
    }else cout << 0;

    return 0;
}
