#### Browser History Function using JavaScript
This repository contains a simple implementation of a browser history function using JavaScript. 
The function allows users to navigate through their browsing history, forward and backward, just like the standard navigation buttons found in web browsers. 
This can be useful for web developers who want to provide a custom user experience for their website's navigation.

#### How it works

The browserHistory function has been created with initialization of array and index variables.
On visiting any page it will put it back in to th array and incras the size
of the index. If the index is -1 ie its a blank page. 

other ways to implement it

The browser history function is implemented using the window.history object in JavaScript. When a user clicks on a link, 
the function stores the URL in an array. The function then uses the pushState method to add a new state to the browser history, 
with the URL and a custom state object containing additional information, such as the title of the page.
When the user clicks on the back or forward button, the function uses the popstate event to get the previous or next state from the browser history. 
It then updates the URL and other information on the page accordingly.
