/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shintarokohtake <shintarokohtake@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:27:29 by shintarokoh       #+#    #+#             */
/*   Updated: 2025/08/01 21:17:37 by shintarokoh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

typedef	struct s_node
{
	int	value;
	struct s_node	*next;
}	t_node;

typedef	struct	s_stack
{
	t_node	*top_ptr;
	int	size;
	char	name;
}	t_stack;

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if(!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return(new_node);	
}

void	push_to_stack_top(t_stack *stack, t_node *new_node)
{
	if(!stack || !new_node)
		return;
	new_node->next = stack->top_ptr;
	stack->top_ptr = new_node;
	stack->size++;
}

// you must comment out the function below
void	my_print_all_nodes_in_stack(t_stack *stack_ptr)
{
	t_node *tmp_node;

	ft_printf(" --- print all nodes in stack --- \n");
	tmp_node = stack_ptr->top_ptr;
	while(tmp_node)
	{
		ft_printf("%d\n",tmp_node->value);
		tmp_node = tmp_node->next;
	}
	ft_printf(" --- finished printing --- \n");
}

// you must comment out the function below
void	double_free_stack(t_stack *stack_ptr)
{
	t_node	*tmp_node;

	if(!stack_ptr || !(stack_ptr->top_ptr))
		return;
	tmp_node = stack_ptr->top_ptr;
	while(tmp_node)
	{
		free(tmp_node);
		tmp_node = tmp_node->next;
	}
	free(stack_ptr);
}

void	pop_from_stack_top(t_stack *stack)
{
	t_node	*popping_node;
	
	if(!stack || !(stack->top_ptr))
		return;
	// popping_node = stack->top_ptr;
	stack->top_ptr = (stack->top_ptr)->next;
	stack->size--;
}

int	main()
{
	t_stack	*tmp_stack;
	t_node	*tmp_node;
	
	tmp_stack = (t_stack *)malloc(sizeof(t_stack));
	if(!tmp_stack)
	{
		return (1);
	}
	tmp_node = create_node(111);
	if(!tmp_node)
	{
		free(tmp_stack);
		return (1);
	}
	push_to_stack_top(tmp_stack, tmp_node);

	tmp_node = create_node(222);
	if(!tmp_node)
	{
		free(tmp_stack);
		return (1);
	}
	push_to_stack_top(tmp_stack, tmp_node);
	my_print_all_nodes_in_stack(tmp_stack);
	double_free_stack(tmp_stack);
	return (0);
}
