#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int Num;
    string seat;
}Per[2];
int judge(string a,string b){
    if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')) return 1;
    else if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')) return 1;
    else return 0;
}
int seatnext(string a,string b){
    if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[2]=='A') return 1;
    else if(a[2]=='B'&&b[2]=='C'||a[2]=='C'&&b[2]=='B') return 1;
    else if(a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D') return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>Per[0].Num>>Per[0].seat>>Per[1].Num>>Per[1].seat;
    if(Per[0].Num==Per[1].Num) cout<<1;
    else cout<<0;
    if(Per[0].seat[0]==Per[1].seat[0]&&Per[0].seat[1]==Per[1].seat[1]){
        cout<<1;
        if(judge(Per[0].seat,Per[1].seat)) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    if(seatnext(Per[0].seat,Per[1].seat)) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
