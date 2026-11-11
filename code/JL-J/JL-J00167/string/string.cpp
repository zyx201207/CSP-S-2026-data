#include<bits/stdc++.h>
using namespace std;
vector<long long> flags;
vector<char> char1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    long long x;
    char y;
    flags.push_back(0);
    long long length=0;
    while(n--){
        cin>>x>>y;
        long long t=flags[flags.size()-1]+x;
        if(char1.size()!=0 && char1[char1.size()-1]==y){
            flags[flags.size()-1]=flags[flags.size()-1]+x;
        }
        else{
            flags.push_back(t);
            char1.push_back(y);
        }
        length+=x;
    }
    vector<long long> turn_flags;
    vector<char> turn_char1;
    for(int i=0;i<flags.size();i++){
        turn_flags.push_back(length-flags[flags.size()-i-1]);
    }
    for(int i=0;i<char1.size();i++){
        turn_char1.push_back(char1[char1.size()-i-1]);
    }
    long long re=0;
    long long flag1=0,flag2=0,pos=0,max1=flags.size()-1;;
    while(flag1<max1 && flag2<max1){
        if(flag1==max1-1 && flag2==max1-1){
            if(char1[flag1] !=turn_char1[flag2]){
                re+=(flags[max1]-max(flags[flag1],turn_flags[flag2]));
            }
            break;
        }
        if(flags[flag1+1]<=turn_flags[flag2+1]){
            if(char1[flag1] !=turn_char1[flag2]){
                re+=flags[flag1+1]-max(flags[flag1],turn_flags[flag2]);
            }
            flag1++;
        }
        else{
            if(char1[flag1] !=turn_char1[flag2]){
                re+=turn_flags[flag2+1]-max(flags[flag1],turn_flags[flag2]);
            }
            flag2++;
        }
    }
    cout<<re/2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
