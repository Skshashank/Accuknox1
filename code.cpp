#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
  
    map<int,pair<set<int>,int>>m;//m is log of restro
    int n;
    cout<<"write number of items"<<endl; //number of items
    cin>>n;
    cout<<"write number of identity"<<endl;
    
    
    for(int x=0;x<n;++x)
    {
        int p;
  
  
        cin>>p;
        set<int>st;
        m[p]={st,0};
    }
    //now customer can enter the eater_id and foodmenu_id which will be saved in this logof restro
  
  
  
   
    cout<<"write number of food eaters"<<endl;
    int m;
    cin>>m;
  
  
    for(int x=0;x<m;++x)
    {
        int p,f;
        cout<<"write food eaterid and id"<<endl;
        cin>>p>>f;
        if(m[f].first.find(p)!=m[f].first.end())
        cout<<"no response same person eating same food";
        else{
            int c=m[f].second;
            c++;
            set<int> st=m[f].first;
            st.insert(p);
  
  
            m[f]={st,c};
        }
    }
    
    
  
  
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>result;
    for(auto x:m)
  
  
    {
        if(result.size()>3 && result.top().first<x.second.second) // this works if frequency is repeated
        result.pop();
        else if(result.size()<3)
        result.push({x.second.second,x.first});
    }
    //the top 3 food menu ids are(if n >3 else it will return 0's after n ids)
    // if all food items are ordered once then it returns last ordered food items
  
  
  
    for(int i=0;i<min(n,3);i++)
    {
        cout<<result.top().second<<endl;
        result.pop();
    }
    return 0;
    
    
}

